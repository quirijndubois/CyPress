# From: https://gist.github.com/averagesecurityguy/ba8d9ed3c59c1deffbd1390dafa5a3c2

#!/usr/bin/env python3
# This script is designed to do one thing and one thing only. It will find each
# of the FlateDecode streams in a PDF document using a regular expression,
# unzip them, and print out the unzipped data. You can do the same in any
# programming language you choose.
#
# This is NOT a generic PDF decoder, if you need a generic PDF decoder, please
# take a look at pdf-parser by Didier Stevens, which is included in Kali linux.
# https://tools.kali.org/forensics/pdf-parser.
#
# Any requests to decode a PDF will be ignored.
import re
import zlib

pdf = open("C:\\Users\\pieterteb\\DuBaTeX\\PDF_testing\\pdf_flatedecode\\main.pdf", "rb").read()
stream = re.compile(rb'.*?FlateDecode.*?stream(.*?)endstream', re.S)

for s in stream.findall(pdf):
    s = s.strip(b'\r\n')
    try:
        print(zlib.decompress(s))
        print("")
    except:
        pass