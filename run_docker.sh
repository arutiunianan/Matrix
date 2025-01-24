#!/bin/bash

docker build -t matrix_image -f docker/Dockerfile .
docker run --name matrix_container matrix_image > docker/docker.txt 2> docker/dockererr.txt

docker rm matrix_container
docker rmi matrix_image