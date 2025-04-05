#!/usr/bin/env ruby
require 'erb'

template = File.read(File.expand_path(ARGV[0]))
output = File.open(File.expand_path(ARGV[1]), 'w')
TESTS_FOLDER = ARGV[2]

t = ERB.new(template)
output.write(t.result)
output.close