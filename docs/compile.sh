#!/bin/bash

nix-shell -p texliveTeTeX rubber --run "rubber -d notes.tex"
