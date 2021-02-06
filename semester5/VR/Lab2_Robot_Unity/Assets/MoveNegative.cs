using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveNegative : MonoBehaviour
{
    private float angle = 0.0f;
    private float v = -50.0f; //velocity
    private const float min = -35.0f; //minimum
    private const float max = 35.0f; //maximum
    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {

        float dt = Time.deltaTime; //seconds
        float delta_angle = v * dt;
        angle += delta_angle;
        if (angle < min || angle > max)
        {
            v *= -1.0f;
            delta_angle *= -1.0f;
            angle += 2 * delta_angle;
        }

        transform.Rotate(Vector3.right, delta_angle);


    }
}
