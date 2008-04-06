#!/bin/python

import re
import sys

pat = re.compile(r'(.*)\s+-\s+(.*)$')

file = open(sys.argv[1])

lista = {}
for line in file:
	match = pat.match(line)
	if match:
		candidato = match.group(1)
		partito = match.group(2)
		partito = partito.rstrip('\r')
		if not lista.has_key(partito):
			lista[partito] = []
		lista[partito].append(candidato)

for partito, candidati in lista.iteritems():
	print partito
	i = 1
	for candidato in candidati:
		print '%d) %s' % (i, candidato)
		i += 1
