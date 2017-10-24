class hello_define {
    define hello_define ($content_variable) {
      file {"$title":
        ensure  => file,
        content => $content_variable,
      }
    }

    hello_define {'/tmp/hello_define1':
      content_variable => "Hello World. This is first define\n",
    }

    hello_define {'/tmp/hello_define2':
      content_variable => "This is my second define. Greeting from soivi.net\n",
    }
}
