using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class play_stop : MonoBehaviour
{
    AudioSource sound;
    private bool play = false;
    // Start is called before the first frame update
    void Start()
    {
        sound = GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        /*
        if (play == true)
        {
            sound.Play();
        }
        else
        {
            sound.Stop();
        }
        */

    }

    private void OnTriggerEnter(Collider other)
    {
        //play = !play;
        sound.Play();
    }

    private void OnTriggerExit(Collider other)
    {
        sound.Stop();
    }
}
