using System;
public class Example
{
  public static void Main()
  {
    print_s21_is_equal(2, 3, 1);
    print_s21_is_equal(-2, -3, 2);
    print_s21_is_equal(2, -3, 3);
    print_s21_is_equal(-2, 3, 4);
    print_s21_is_equal(3, 2, 5);
    print_s21_is_equal(-3, -2, 6);
    print_s21_is_equal(3, -2, 7);
    print_s21_is_equal(-3, 2, 8);
    print_s21_is_equal(3, 3, 9);
    print_s21_is_equal(-3, -3, 10);
    print_s21_is_equal(3, -3, 11);
    print_s21_is_equal(-3, 3, 12);
    print_s21_is_equal(0, 0, 13);
    print_s21_is_equal(-0, 0, 14);
    print_s21_is_equal(3.2M, 3.3M, 15);
    print_s21_is_equal(-3.2M, -3.3M, 16);
    print_s21_is_equal(-3.2M, 3.3M, 17);
    print_s21_is_equal(3.2M, -3.3M, 18);
    print_s21_is_equal(12345677.98765434567898765434567M, 87654323456.9876545678987653M, 19);
    print_s21_is_equal(-12345677.98765434567898765434567M, -87654323456.9876545678987653M, 20);
    print_s21_is_equal(12345677.98765434567898765434567M, -87654323456.9876545678987653M, 21);
    print_s21_is_equal(-12345677.98765434567898765434567M, 87654323456.9876545678987653M, 22);
    print_s21_is_equal(79228162514264337593543950335M, 1, 23);
    print_s21_is_equal(-79228162514264337593543950335M, -1, 24);
    print_s21_is_equal(-79228162514264337593543950335M, 1, 25);
    print_s21_is_equal(79228162514264337593543950335M, -1, 26);
    print_s21_is_equal(7922816251427554395M, 65645646M, 27);
    print_s21_is_equal(665464545M, 8798232189789785M, 28);
    print_s21_is_equal(2.7986531268974139743M, 9.979623121254565121244554M, 29);
    print_s21_is_equal(-9798956154578676.7975645341564864545454M, -2156878451.854764M, 30);
    print_s21_is_equal(0.545646546548647684654546548464M, 0.68985125146545154M, 31);
    print_s21_is_equal(-0.77545545454546589781M, 87894515154546456456M, 32);
    print_s21_is_equal(-79228162514264337593543950335M, 1, 33);
    print_s21_is_equal(32323465788987654, 67543278.89765424354657687M, 34);
    print_s21_is_equal(-784515454.7989898652154545652M, -579895323215489956.67897455465M, 35);
    print_s21_is_equal(0, -37986322154988653.784354545764545454543454M, 36);
    print_s21_is_equal(1.0M, 0.0M, 37);
    print_s21_is_equal(-1.0M, -0.0M, 38);
    print_s21_is_equal(1.0M, -0.0M, 39);
    print_s21_is_equal(-1.0M, 0.0M, 40);
    print_s21_is_equal(79228162514264337593543950335M, 79228162514264337593543950335M, 41);
    print_s21_is_equal(-79228162514264337593543950335M, -79228162514264337593543950335M, 42);
    print_s21_is_equal(79228162514264337593543950335M, -79228162514264337593543950335M, 43);
    print_s21_is_equal(-79228162514264337593543950335M, 79228162514264337593543950335M, 44);
  }

  public static void print_s21_is_equal(decimal number1, decimal number2, int num)
  {
    int origin = 0;
    if(number1 < number2) origin = 1;
    Console.WriteLine("#test s21_s21_is_less{0}\n", num);
    Console.WriteLine("  s21_decimal src1, src2;\n");
    int[] bits1 = decimal.GetBits(number1);
    Console.WriteLine("  // src1 = {0};\n  // src2 = {1};\n", number1, number2);
    Console.WriteLine("  src1.bits[0] = 0b{0};\n  src1.bits[1] = 0b{1};\n  src1.bits[2] = 0b{2};\n  src1.bits[3] = 0b{3};\n",
          Convert.ToString(bits1[0], 2).PadLeft(32, '0'),
          Convert.ToString(bits1[1], 2).PadLeft(32, '0'),
          Convert.ToString(bits1[2], 2).PadLeft(32, '0'),
          Convert.ToString(bits1[3], 2).PadLeft(32, '0'));
    int[] bits2 = decimal.GetBits(number2);
    Console.WriteLine("  src2.bits[0] = 0b{0};\n  src2.bits[1] = 0b{1};\n  src2.bits[2] = 0b{2};\n  src2.bits[3] = 0b{3};\n",
          Convert.ToString(bits2[0], 2).PadLeft(32, '0'),
          Convert.ToString(bits2[1], 2).PadLeft(32, '0'),
          Convert.ToString(bits2[2], 2).PadLeft(32, '0'),
          Convert.ToString(bits2[3], 2).PadLeft(32, '0'));
    Console.WriteLine("  int result = s21_is_less(src1, src2);\n");
    Console.WriteLine("  int origin = {0};\n", origin.ToString());
    Console.WriteLine("  ck_assert_int_eq(origin, result);\n");
  }
}
