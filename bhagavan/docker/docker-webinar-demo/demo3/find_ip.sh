#! /bin/bash

docker inspect --format='{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' redis-db