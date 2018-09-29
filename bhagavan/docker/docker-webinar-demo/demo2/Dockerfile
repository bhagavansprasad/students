FROM node:argon

ENV TERM xterm

# Install my favorite node modules for development globally
RUN npm install -g nodemon

# make a folder for our code
RUN mkdir code

# move our current package.json in there to install modules
COPY src/package.json code

# Go into our code directory
WORKDIR code

# let's install our Node.JS modules!
RUN npm install

# expose the port our code will use!
EXPOSE 3000

# this runs forever as a daemon so my container will stay up until I tell it to stop
CMD nodemon hello.js