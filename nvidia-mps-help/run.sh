#!/bin/bash

echo Starting Server
./start-server.sh

echo Running kernel time test
./t1034 &
./t1034


echo Stop Server
./stop-server.sh

echo Running kernel time test
./t1034 &
./t1034



