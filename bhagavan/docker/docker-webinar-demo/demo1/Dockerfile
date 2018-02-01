FROM node:argon

ENV TERM xterm

# make a folder for our code
RUN mkdir code

# Copy our code over so we can run it!
COPY src/* code/

# Go into our code directory
WORKDIR code

# install our node modules
RUN npm install

# Run our code!
CMD node hello.js