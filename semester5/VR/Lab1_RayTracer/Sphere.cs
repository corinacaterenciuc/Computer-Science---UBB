using System;
using System.Runtime.InteropServices.WindowsRuntime;

namespace rt
{
    public class Sphere : Geometry
    {
        private Vector Center { get; set; }
        private double Radius { get; set; }

        public Sphere(Vector center, double radius, Material material, Color color) : base(material, color)
        {
            Center = center;
            Radius = radius;
        }

        public override Intersection GetIntersection(Line line, double minDist, double maxDist)
        {
            // ADD CODE HERE: Calculate the intersection between the given line and this sphere
            double A = line.Dx.X * line.Dx.X + line.Dx.Y * line.Dx.Y + line.Dx.Z * line.Dx.Z;
            double B = 2 * (line.Dx.X * line.X0.X - line.Dx.X * Center.X + line.Dx.Y * line.X0.Y - line.Dx.Y * Center.Y + line.Dx.Z * line.X0.Z - line.Dx.Z * Center.Z);

            double x0xc = (line.X0.X - Center.X) * (line.X0.X - Center.X);
            double y0yc = (line.X0.Y - Center.Y) * (line.X0.Y - Center.Y);
            double z0zc = (line.X0.Z - Center.Z) * (line.X0.Z - Center.Z);

            double C = x0xc + y0yc + z0zc - Radius * Radius;

            double Delta = B * B - 4 * A * C;

            double t1, t2;

            if(Delta < 0)
            {
                return new Intersection();
            }
            else if(Delta == 0)
            {
                double t = -B / (2 * A);
                Vector intersection = line.CoordinateToPosition(t);

                bool visible = true;

                double len = (intersection - line.X0).Length();

                if (len < minDist || len > maxDist || t < 0)
                    visible = false;

                return new Intersection(true, visible, this, line, t);

            }
            else 
            {
                t1 = (-B + Math.Sqrt(Delta)) / (2 * A);
                t2 = (-B - Math.Sqrt(Delta)) / (2 * A);
                bool visible = true;

                if(t1 < t2)
                {
                    Vector intersection = line.CoordinateToPosition(t1);

                    double len = (intersection - line.X0).Length();
                    if (len < minDist || len > maxDist || t1 < 0)
                        visible = false;

                    return new Intersection(true, visible, this, line, t1);
                }
                else
                {
                    Vector intersection = line.CoordinateToPosition(t2);

                    double len = (intersection - line.X0).Length();
                    if (len < minDist || len > maxDist || t2 < 0)
                        visible = false;

                    return new Intersection(true, visible, this, line, t2);
                }

            }

            //return new Intersection();
        }

        public override Vector Normal(Vector v)
        {
            var n = v - Center;
            n.Normalize();
            return n;
        }
    }
}