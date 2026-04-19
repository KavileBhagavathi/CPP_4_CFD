#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Fri Apr 10 15:14:40 2026

@author: arjun-raf
"""
import os
import sys
import glob
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


def oneD_convection_animator(filepath):
    # Load all text files
    files = sorted(glob.glob(filepath+"*.txt"))  # adjust path/pattern
    datasets = [np.loadtxt(f) for f in files]  
    # Setup figure
    fig, ax = plt.subplots(figsize=(10, 5))
    line, = ax.plot([], [], marker='o')
    
    # Set axis limits based on all data
    all_values = np.concatenate(datasets)
    ax.set_xlim(0, max(len(d) for d in datasets) - 1)
    ax.set_ylim(all_values.min() - 1, all_values.max() + 1)
    ax.set_xlabel("x")
    ax.set_ylabel("Amplitude")
    ax.grid(True)
    
    def init():
        line.set_data([], [])
        return line,
    
    def update(frame):
        data = datasets[frame]
        line.set_data(range(len(data)), data)
        ax.set_title(f"File: {files[frame]}")
        return line,
    
    ani = animation.FuncAnimation(
        fig,
        update,
        frames=len(datasets),
        init_func=init,
        interval=300,    # milliseconds between frames
        repeat=True
    )
    ani.save("animation.gif", writer="pillow", fps=2)  # save as GIF
    
if __name__ == "__main__":
    if len(sys.argv) < 2:
        raise Exception("Provide folder path as argument!")
    foldername = sys.argv[1]
    filepath = '../'+foldername+'/results/'
    if "1D" in foldername:
        oneD_convection_animator(filepath)
        
    