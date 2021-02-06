using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LookAtMouse : MonoBehaviour
{
    Vector3 worldPosition;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
        Vector3 mouse_pos = Input.mousePosition;
        mouse_pos.z = 5.0f; //distance of the plane from the camera
        worldPosition = -Camera.main.ScreenToWorldPoint(mouse_pos);
        transform.LookAt(worldPosition);
        

    }
}
