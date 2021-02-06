using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cannon_shoot : MonoBehaviour
{
    public GameObject cannon_ball;
    public float rate_of_fire = 0.5f;
    public float speed = 30f;
    float fire_delay = 0f;
    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        if( Input.GetButton("Fire1") && Time.time > fire_delay)
        {
            fire_delay = Time.time + rate_of_fire;
            GameObject clone = Instantiate(cannon_ball, transform.position, transform.rotation);
            clone.GetComponent<Rigidbody>().velocity = transform.TransformDirection(new Vector3(0, speed, 0));
            Physics.IgnoreCollision(clone.GetComponent<Collider>(), transform.root.GetComponent<Collider>());
        }
    }
}
