using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PointAt : MonoBehaviour
{
    Vector3 target = Vector3.zero;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //transform.LookAt(target);

        Vector3 dir = transform.InverseTransformPoint(target);
        Vector3 me = Vector3.forward;
        Vector3 axis = Vector3.Cross(me, dir);
        //float angle = Vector3.Angle(me, dir);
        float angle = (float)(180 * Math.Acos(Vector3.Dot(me.normalized, dir.normalized))/Math.PI);
        transform.Rotate(axis, angle);
    }
}
