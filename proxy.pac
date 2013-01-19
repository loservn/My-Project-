function FindProxyForURL(url, host) {
    // Your proxy server name and port
    var torsock = 'localhost:9050';
    //
    //  Here's a list of hosts to connect via the PROXY server
    //
    var proxylist = new Array(
        "*.uit.edu.vn",
        "forum.uit.edu.vn",
        "www.cyberciti.biz",
        "mail.google.com",
        "www.pandora.com",
        "www.google.com",
	"www.google.com.vn"
	"www.hvaonline.net"
    );
    // Return our proxy name for matched domains/hosts
    for(var i=0; i<proxylist.length; i++) {
        var value = proxylist[i];
        if ( localHostOrDomainIs(host, value) ) {
            return "DIRECT";
        }
    }
    return "SOCKS "+torsock;
}
