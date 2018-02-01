#! /bin/bash

docker run -d -v /Users/nodebotanist/Dev/work/demos/docker-webinar/demo2/src:/code -p 1338:3000 --name dev2 dev:2.0