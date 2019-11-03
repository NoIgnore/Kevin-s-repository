using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.IO.Compression;
using System.Net;
using System.Text;

namespace FuckCNSS
{
    public class http
    {
        public string Proxy { get; set; }
        public int TimeOut { get; set; }
        public string UserAgent { get; set; }
        public string Referer { get; set; }
        public bool Redirect { get; set; }
        public Encoding Encoding { get; set; }
        public string Host { get; set; }
        public string Accept { get; set; }
        public bool UseGZIP { get; set; }
        const string ContentTYPE = "application/x-www-form-urlencoded";
        /// <summary>
        /// Request Method
        /// </summary>
        public const string MethodGET = "GET";
        /// <summary>
        /// Request Method
        /// </summary>
        public const string MethodPOST = "POST";

        public http()
        {
            Init(16);

        }
        public http(int ConnectionLimit)
        {
            Init(ConnectionLimit);
        }
        /// <summary>
        /// Initiate http setting
        /// </summary>
        /// <param name="ConnectionLimit"></param>
        private void Init(int ConnectionLimit)
        {
            TimeOut = 10000;//10 s
            UserAgent = "Mozilla/5.0 (Windows NT 10.0) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/50.0.2661.94 Safari/537.36";
            Encoding = Encoding.UTF8;
            Redirect = true;
            UseGZIP = false;
            Host = "";
            SetConnectionLimit(ConnectionLimit);
            void SetConnectionLimit(int num)
            {
                if (num > 0 && num < 1024)
                    ServicePointManager.DefaultConnectionLimit = num;
            }
        }
        /// <summary>
        ///  GET网页请求
        /// </summary>
        /// <param name="url">请求网址</param>
        /// <returns>网页源代码</returns>
        public string Get(string url)
        {
            try
            {
                HttpWebRequest hw = NewHttpWebRequest(url, MethodGET);
                return GetString(hw);
            }
            catch (WebException e)
            {
                return e.Message;
            }
        }
        private string GetString(HttpWebRequest hw)
        {
            HttpWebResponse hwr = (HttpWebResponse)hw.GetResponse();
            if (!UseGZIP)
            {
                StreamReader sr = new StreamReader(hwr.GetResponseStream(), Encoding);
                return sr.ReadToEnd();
            }
            else
            {
                GZipStream gsr = new GZipStream(hwr.GetResponseStream(), CompressionMode.Decompress);
                List<Byte> tBytes = new List<byte>();
                byte[] buff = new byte[1];//如果修改为>2 可能会多出或少了一些内容；所以我选择一个一个的读入！
                int count = 0;
                do
                {
                    count = gsr.Read(buff, 0, buff.Length);
                    if (count != 0)
                    {
                        tBytes.AddRange(buff);
                    }
                } while (count > 0);
                return Encoding.GetString(tBytes.ToArray());
            }
        }

        private HttpWebRequest NewHttpWebRequest(string url, string method)
        {
            HttpWebRequest hw = (HttpWebRequest)WebRequest.Create(url);
            if (Proxy != "") hw.Proxy = new WebProxy(Proxy, true);
            hw.Method = method;
            hw.Timeout = TimeOut;
            hw.ContentType = ContentTYPE;
            hw.UserAgent = UserAgent;
            hw.Referer = Referer;
            hw.AllowAutoRedirect = Redirect;
            //hw.Host = Host;
            hw.Accept = Accept;
            return hw;
        }

        /// <summary>
        ///  GET 请求
        /// </summary>
        /// <param name="url">请求网址</param>
        /// <returns>Stream</returns>
        public Stream GetStream(string url)
        {
            try
            {
                HttpWebRequest hw = NewHttpWebRequest(url, MethodGET);
                HttpWebResponse hwr = (HttpWebResponse)hw.GetResponse();
                return hwr.GetResponseStream();
            }
            catch (WebException e)
            {
                throw e;
            }

        }
        /// <summary>
        ///  GET 请求
        /// </summary>
        /// <param name="url">请求网址</param>
        /// <returns>Stream</returns>
        public Stream GetStream(string url, CookieContainer cc)
        {
            try
            {
                HttpWebRequest hw = NewHttpWebRequest(url, MethodGET);
                hw.CookieContainer = cc;
                HttpWebResponse hwr = (HttpWebResponse)hw.GetResponse();
                return hwr.GetResponseStream();
            }
            catch (WebException e)
            {
                throw e;
            }

        }
        /// <summary>
        /// 网页请求
        /// </summary>
        /// <param name="url">请求地址</param>
        /// <param name="postData">发送数据</param>
        /// <returns>网页源码（出错返回空文本）</returns>
        public string Post(string url, string postData)
        {
            try
            {
                HttpWebRequest hw = NewHttpWebRequest(url, MethodPOST);
                byte[] PD = Encoding.GetBytes(postData);
                Stream Stream = hw.GetRequestStream();
                Stream.Write(PD, 0, PD.Length);
                Stream.Close();
                HttpWebResponse hwr = (HttpWebResponse)hw.GetResponse();
                StreamReader sr = new StreamReader(hwr.GetResponseStream(), Encoding);
                return sr.ReadToEnd();
            }
            catch (WebException e)
            {
                return e.Message;
            }
        }
        /// <summary>
        /// 网页请求
        /// </summary>
        /// <param name="url">请求地址</param>
        /// <param name="postData">发送数据</param>
        /// <returns>网页源码（出错返回空文本）</returns>
        public string Post(string url, string[,] postData)
        {
            try
            {
                HttpWebRequest hw = NewHttpWebRequest(url, MethodPOST);
                string pdStr = NewPostData(postData);
                byte[] PD = Encoding.GetBytes(pdStr);
                Stream Stream = hw.GetRequestStream();
                Stream.Write(PD, 0, PD.Length);
                Stream.Close();
                HttpWebResponse hwr = (HttpWebResponse)hw.GetResponse();
                StreamReader sr = new StreamReader(hwr.GetResponseStream(), Encoding);
                return sr.ReadToEnd();
            }
            catch (WebException e)
            {
                return e.Message;
            }
        }
        /// <summary>
        ///  GET网页请求
        /// </summary>
        /// <param name="url">请求网址</param>
        /// <returns>网页源代码</returns>
        public string Get(string url, ref CookieContainer cc)
        {
            try
            {
                HttpWebRequest hw = NewHttpWebRequest(url, MethodGET);
                hw.CookieContainer = cc;
                return GetString(hw);
            }
            catch (WebException e)
            {
                return e.Message;
            }
        }
        /// <summary>
        /// 网页请求
        /// </summary>
        /// <param name="url">请求地址</param>
        /// <param name="postData">发送数据</param>
        /// <returns>网页源码（出错返回空文本）</returns>
        public string Post(string url, string postData, ref CookieContainer cc)
        {
            try
            {
                HttpWebRequest hw = NewHttpWebRequest(url, MethodPOST);
                hw.CookieContainer = cc;
                byte[] PD = Encoding.GetBytes(postData);
                Stream Stream = hw.GetRequestStream();
                Stream.Write(PD, 0, PD.Length);
                Stream.Close();
                return GetString(hw);
            }
            catch (WebException e)
            {
                return e.Message;
            }
        }
        /// <summary>
        /// 网页请求
        /// </summary>
        /// <param name="url">请求地址</param>
        /// <param name="postData">发送数据</param>
        /// <returns>网页源码（出错返回空文本）</returns>
        public string Post(string url, string[,] postData, ref CookieContainer cc)
        {
            try
            {
                HttpWebRequest hw = NewHttpWebRequest(url, MethodPOST);
                hw.CookieContainer = cc;
                string pdStr = NewPostData(postData);
                byte[] PD = Encoding.GetBytes(pdStr);
                Stream Stream = hw.GetRequestStream();
                Stream.Write(PD, 0, PD.Length);
                Stream.Close();
                return GetString(hw);
            }
            catch (WebException e)
            {
                return e.Message;
            }
        }
        /// <summary>
        /// 获取Cookie的值
        /// </summary>
        /// <param name="cookieName">Cookie名称</param>
        /// <param name="cc">Cookie集合对象</param>
        /// <returns>返回Cookie名称对应值</returns>
        public string GetCookie(string cookieName, CookieContainer cc)
        {
            List<Cookie> lstCookies = new List<Cookie>();
            Hashtable table = (Hashtable)cc.GetType().InvokeMember("m_domainTable",
                                                                   System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.GetField |
                                                                   System.Reflection.BindingFlags.Instance, null, cc, new object[] { });
            foreach (object pathList in table.Values)
            {
                SortedList lstCookieCol = (SortedList)pathList.GetType().InvokeMember("m_list",
                                                                                      System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.GetField
                                                                                      | System.Reflection.BindingFlags.Instance, null, pathList, new object[] { });
                foreach (CookieCollection colCookies in lstCookieCol.Values)
                    foreach (Cookie c1 in colCookies) lstCookies.Add(c1);
            }
            var model = lstCookies.Find(p => p.Name == cookieName);
            if (model != null)
            {
                return model.Value;
            }
            return string.Empty;
        }
        /// <summary>
        /// 获取CookieContainer
        /// </summary>
        /// <param name="url">Cookie的域</param>
        /// <param name="cookie">Cookie值(支持多个如,A=1;B=2;)</param>
        /// <returns></returns>
        public CookieContainer NewCookieContainer(string url, string cookie)
        {
            CookieContainer cc = new CookieContainer();
            cc.SetCookies(new Uri(url), cookie);
            return cc;
        }
        public string NewPostData(string[,] Params)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < Params.GetLength(0); i++)
            {
                sb.Append(Params[i, 0]);
                sb.Append("=");
                sb.Append(Params[i, 1]);
                sb.Append("&");
            }
            sb.Remove(sb.Length - 1, 1);//删除最后一个[&]符号
            return sb.ToString();
        }
    }

}
