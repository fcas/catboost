"""
Wcwidth module.

https://github.com/jquast/wcwidth
"""
# re-export all functions & definitions, even private ones, from top-level
# module path, to allow for 'from wcwidth import _private_func'.  Of course,
# user beware that any _private function may disappear or change signature at
# any future version.

# local
from .wcwidth import ZERO_WIDTH  # noqa
from .wcwidth import (WIDE_EASTASIAN,
                      VS16_NARROW_TO_WIDE,
                      wcwidth,
                      wcswidth,
                      _bisearch,
                      list_versions,
                      _wcmatch_version,
                      _wcversion_value)

# The __all__ attribute defines the items exported from statement,
# 'from wcwidth import *', but also to say, "This is the public API".
__all__ = ('wcwidth', 'wcswidth', 'list_versions')

# We also used pkg_resources to load unicode version tables from version.json,
# generated by bin/update-tables.py, but some environments are unable to
# import pkg_resources for one reason or another, yikes!
__version__ = '0.2.13'
