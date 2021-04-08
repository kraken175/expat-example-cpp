(function () {
  "use strict";

  var expat = require('node-expat')
  var parser = new expat.Parser('UTF-8')

  parser.on('startElement', function (name, attrs) {
    console.log(name, attrs)
  })

  parser.on('endElement', function (name) {
    console.log(name)
  })

  parser.on('text', function (text) {
    console.log(text)
  })

  parser.on('error', function (error) {
    console.error(error)
  })

  parser.write('<html><head><title>Hello World</title></head><body><p>Foobar</p></body></html>')

}())
