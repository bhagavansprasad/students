#! /bin/bash

docker run -d -v /Users/nodebotanist/Dev/work/demos/docker-webinar/demo3/src:/code -p 1339:3000 --name dev3 dev:3.0