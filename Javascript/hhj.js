// ==UserScript==
// @name         抢票
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  try to take over the world!
// @author       You
// @match        https://www.baidu.com/s?wd=autofill%E6%89%A7%E8%A1%8C%E4%BB%A3%E7%A0%81&pn=10&oq=autofill%E6%89%A7%E8%A1%8C%E4%BB%A3%E7%A0%81&tn=02003390_42_hao_pg&ie=utf-8&rsv_pq=bc0cd2c40001ee6e&rsv_t=e64bAEMboBvytCKFHN4qmNpzbekwWhlWEntYhVULo1T0Ys9TgJ33TuWsjMPThBezLZq0MNs5h5SL&rsv_page=1
// @icon         https://www.google.com/s2/favicons?domain=baidu.com
// @grant        none
// @include     *://*f.lingxi360.com/*
// ==/UserScript==

(function() {
    'use strict';
    var now;
    var hhj=0;
    function doCompareTime()
    {
        var b = new Date();
        var tHour=b.getHours();
        var tMinute=b.getMinutes();
        var tSecond=b.getSeconds();
        now = (tHour<10?"0"+tHour:tHour)+":"+(tMinute<10?"0"+tMinute:tMinute)+":"+(tSecond<10?"0"+tSecond:tSecond);
        if(now>="12:00:00")
        {
            try
            {
                var module1 = document.getElementsByClassName("form-control");
                module1[1].value='xxx';//number
                module1[0].value='xxx';//name

            }
            catch(error)
            {
                document.getElementById("name").value='xxx';//name
                document.getElementById("new_item_1").value='xxx';//number
            }
            document.getElementById("button").click();
        }
        location.reload();
    }
    setInterval(doCompareTime(),1000);
})();