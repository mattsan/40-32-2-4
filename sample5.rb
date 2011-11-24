class Factorial
  def initialize
    @factorial = []
  end

  def get(n)
    @factorial << ((n > 0) ? (n * get(n - 1)) : 1) if @factorial.size() <= n
    return @factorial[n]
  end

  def lower_bound(a)
    result = 0
    while get(result) < a
      result += 1
    end
    result - 1
  end
end

def is_divisible(dividend, divisor)
  ((dividend / divisor) * divisor) == dividend
end

def print_abc(a, b, c)
  m = (a - b) / c
  n = a - b / c
  puts "(#{a} - #{b}) / #{c} = #{m}"
  puts " #{a} - #{b}  / #{c} = #{m}! = #{n}"
  puts
end

Max = ARGV.shift.to_i

factorial = Factorial.new

(1...Max).each do |a|
  m = factorial.lower_bound a
  (1..m).each do |n|
    b1 = a - factorial.get(n)
    c  = 2
    while (b1 * c) < a
      b = b1 * c
      if is_divisible(a - b, c) && (((a - b) / c) == n)
        print_abc(a, b, c)
      end
      c += 1
    end
  end
end
