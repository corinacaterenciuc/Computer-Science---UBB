using System;
using System.Runtime.InteropServices;

namespace rt
{
    class RayTracer
    {
        private Geometry[] geometries;
        private Light[] lights;

        public RayTracer(Geometry[] geometries, Light[] lights)
        {
            this.geometries = geometries;
            this.lights = lights;
        }

        private double ImageToViewPlane(int n, int imgSize, double viewPlaneSize)
        {
            var u = n * viewPlaneSize / imgSize;
            u -= viewPlaneSize / 2;
            return u;
        }

        private Intersection FindFirstIntersection(Line ray, double minDist, double maxDist)
        {
            var intersection = new Intersection();

            foreach (var geometry in geometries)
            {
                var intr = geometry.GetIntersection(ray, minDist, maxDist);

                if (!intr.Valid || !intr.Visible) continue;

                if (!intersection.Valid || !intersection.Visible)
                {
                    intersection = intr;
                }
                else if (intr.T < intersection.T)
                {
                    intersection = intr;
                }
            }

            return intersection;
        }

        private bool IsLit(Vector point, Light light)
        {
            // ADD CODE HERE: Detect whether the given point has a clear line of sight to the given light

            Line ray = new Line(point, light.Position);
            double d = (light.Position - point).Length();
            Intersection intersect = FindFirstIntersection(ray, 0, d);

            return !(intersect.Valid); //&& intersect.Visible);
        }

        public void Render(Camera camera, int width, int height, string filename)
        {
            var background = new Color(0,0,0,0); 
            var viewParallel = (camera.Up ^ camera.Direction).Normalize();

            var image = new Image(width, height);

            var vecW = camera.Direction * camera.ViewPlaneDistance;
            for (var i = 0; i < width; i++)
            {
                for (var j = 0; j < height; j++)
                {
                    // ADD CODE HERE: Implement pixel color calculation

                    Vector x1 = camera.Position + camera.Direction * camera.ViewPlaneDistance + viewParallel * ImageToViewPlane(i, width, camera.ViewPlaneWidth) + camera.Up * ImageToViewPlane(j, height, camera.ViewPlaneHeight);
                    Line ray = new Line(camera.Position, x1);
                    Intersection intersect = FindFirstIntersection(ray, camera.FrontPlaneDistance, camera.BackPlaneDistance);

                    if(intersect.Valid && intersect.Visible)
                    {
                        Color color = new Color();
                        //color += intersect.Geometry.Color;

                        
                        foreach (var light in lights)
                        {
                            color += intersect.Geometry.Material.Ambient * light.Ambient;
                            bool isLit = IsLit(intersect.Position, light);

                            if(isLit)
                            {
                                Vector N = intersect.Geometry.Normal(intersect.Position);
                                Vector T = (light.Position - intersect.Position).Normalize();
                                Vector E = (camera.Position - intersect.Position).Normalize();
                                Vector R = N * (N * T) * 2 - T;

                                if(N * T > 0)
                                {
                                    color += intersect.Geometry.Material.Diffuse * light.Diffuse * (N * T);
                                }
                                if(E * R > 0)
                                {
                                    color += intersect.Geometry.Material.Specular * light.Specular * Math.Pow(E * R, intersect.Geometry.Material.Shininess);
                                }
                                color *= light.Intensity;
                            }
                        }

                        image.SetPixel(i, j, color);
                    }
                    else
                        image.SetPixel(i, j, background);
                }
            }

            image.Store(filename);
        }
    }
}