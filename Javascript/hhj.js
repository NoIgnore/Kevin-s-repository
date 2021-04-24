// ==UserScript==
// @name         抢票
// @namespace    http://tampermonkey.net/
// @version      0.1
// @description  try to take over the world!
// @author       You
// @match        *://*f.lingxi360.com/*
// @icon         https://www.google.com/s2/favicons?domain=baidu.com
// @grant        none
// @include     *://*f.lingxi360.com/*
// ==/UserScript==

(function() {
    'use strict';
    var get_id = 0;
    var get_classname = 0;
    function doCompareTime()
    {
        var myname='xxx';
        var mynumber='xxxxxxxxxxxxx';
        try
        {
            document.getElementById("new_item_1").value=mynumber;
            document.getElementById("name").value=myname;
            document.getElementById("button").click();
            get_id = 0;
        }
        catch(error)
        {
            get_id=1;
        }
        try
        {
            var module1 = document.getElementsByClassName("form-control");
            module1[1].value=mynumber;
            module1[0].value=myname;
            document.getElementById("button").click();
            get_classname = 0;
        }
        catch(error)
        {
            get_classname=1;
        }
        if(get_classname==1&&get_id==1)
        {
            location.reload();
        }
    }
    setInterval(doCompareTime(),1000);
})();