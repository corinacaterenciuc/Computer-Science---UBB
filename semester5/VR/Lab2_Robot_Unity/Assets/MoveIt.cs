using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveIt : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        float v = 40.0f; //velocity
        float dt = Time.deltaTime; //seconds

        transform.Rotate(Vector3.right, v * dt);

        /*
        transform.Rotate(Vector3.right, v * dt);
        transform.Rotate(Vector3.up, v * dt);
        transform.Rotate(Vector3.forward, v * dt);
        */
        
    }
}
