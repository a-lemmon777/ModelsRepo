#!/usr/bin/ruby

numLines = ARGV[0].to_i
fileName = "file#{numLines}.txt"

File.open(fileName, 'w') do |f| 
  numLines.times do |n|
    f.puts(n)
  end
end

