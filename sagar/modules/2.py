import types
import unittest

print([unittest.__dict__.get(a) for a in dir(unittest)
  if isinstance(unittest.__dict__.get(a), types.FunctionType)])
