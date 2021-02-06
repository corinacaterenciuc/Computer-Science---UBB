using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BellRing : MonoBehaviour
{
    private AudioSource bellRing;
    // Start is called before the first frame update
    void Start()
    {
        bellRing = GetComponent<AudioSource>();
        
    }

    void OnCollisionEnter(Collision collision)
    {
        bellRing.Play();
    }
}
