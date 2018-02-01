'use strict'

const express = require('express')
const redis = require('redis')

let app = express()
let client = redis.createClient({
  host: 'redis'
})

app.get('/', function (req, res) {
  let key = req.query.key
  let val = req.query.val
  if(key && val){
    client.set(key, val, function(err){
      if(err){
        res.send(err)
      } else {
        res.send('Key ' + key + ' set with ' + val)
      }
    })
  } else if(key){
    client.get(key, function(err, result){
      if(err){
        res.send(err)
      } else if(result !== 'null'){
        res.send('Your value for ' + key + ' was ' + result)
      } else {
        res.send('No value stored for ' + key + '!')
      }
    })
  } else {
    res.send('Hello Webinar!')
  }
})

app.listen(3000, function () {
  console.log('Example app listening on port 3000!');
});