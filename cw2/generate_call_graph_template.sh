#!/usr/bin/bash
/home/csunix/usr/path/to/egypt $@ | dot -Gsize=8,11  -Tpdf -o UniBotCallGraph.pdf
