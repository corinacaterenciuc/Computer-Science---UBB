using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Open2Door : MonoBehaviour
{
    public Transform Door;
    public Vector3 openRotation = new Vector3(0f, 90f, 0f);

    public float openSpeed = 6;

    private bool open = false;
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if (open == true)
        {
            Door.rotation = Quaternion.Lerp(Door.rotation,
            Quaternion.Euler(openRotation), Time.deltaTime * openSpeed);
        }
        else
        {
            Door.rotation = Quaternion.Lerp(Door.rotation,
            Quaternion.Euler(0f, 0f, 0f), Time.deltaTime * openSpeed);
        }

    }

    private void OnTriggerEnter(Collider other)
    {
        open = true;
    }

    private void OnTriggerExit(Collider other)
    {
        open = false;
    }
}
