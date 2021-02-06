using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OpenDoor : MonoBehaviour
{
    public Transform rightDoor;
    public Transform leftDoor;
    public Vector3 openRotationRight = new Vector3(0f, 110f, 0f);
    public Vector3 openRotationLeft = new Vector3(0f, -110f, 0f);

    public float openSpeed = 5;

    private bool open = false;

    // Start is called before the first frame update
    void Start()
    {

    }

    // Update is called once per frame
    void Update()
    {
        if (open == true)
        {
            rightDoor.rotation = Quaternion.Lerp(rightDoor.rotation,
            Quaternion.Euler(openRotationRight), Time.deltaTime * openSpeed);
            leftDoor.rotation = Quaternion.Lerp(leftDoor.rotation,
            Quaternion.Euler(openRotationLeft), Time.deltaTime * openSpeed);
        }
        else 
        {
            rightDoor.rotation = Quaternion.Lerp(rightDoor.rotation,
            Quaternion.Euler(0f, 0f, 0f), Time.deltaTime * openSpeed);
            leftDoor.rotation = Quaternion.Lerp(leftDoor.rotation,
            Quaternion.Euler(0f, 0f, 0f), Time.deltaTime * openSpeed);
        }

    }

    private void OnTriggerEnter(Collider other)
    {
        open = !open;
    }

    private void OnTriggerExit(Collider other)
    {
        //open = false;
    }

}
