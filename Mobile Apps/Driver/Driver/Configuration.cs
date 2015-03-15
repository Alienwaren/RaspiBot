using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;
using System.Xml;
namespace Driver
{
    public class Configuration
    {
        public Configuration(Uri xmlFile, Uri xsdFile)
        {
            configuration = XDocument.Load(xmlFile.ToString());
            readConfiguration();
        }
        void readConfiguration()
        {
            String ip = configuration.Descendants(XName.Get("ipAddress")).FirstOrDefault().Value;
            String port = configuration.Descendants(XName.Get("port")).FirstOrDefault().Value;
            if(ip != null && port != null)
            {
                Options.ip = ip;
                Options.port = port;
            }
        }
        void writeConfiguration(String newIp, String newPort)
        {
            configuration.Descendants(XName.Get("ipAddress")).FirstOrDefault().Value = newIp;
            configuration.Descendants(XName.Get("port")).FirstOrDefault().Value = newPort;
        }
        private XDocument configuration;
    }
}
