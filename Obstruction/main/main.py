'''
Created on Dec 30, 2018

@author: Korina
'''
from UI.console import Console
from UI.GUI import GUI

def read_settings():
    settings = {}
    with open("settings" , "r") as f:
        t = f.readline()
        while len(t)>1:
            tok = t.split("=")
            settings[tok[0].strip()] = tok[1].strip()
            t = f.readline()
            
    return settings
            
             
settings = read_settings()

if settings["ui"] == "console":
    ui = Console()
elif settings["ui"] == "GUI":
    ui = GUI()

ui.start()