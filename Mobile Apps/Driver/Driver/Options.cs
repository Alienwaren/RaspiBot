using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Driver
{
    public static class Options
    {
        static private String carIp;

        static public String ip
        {
            get { return carIp; }
            set { carIp = value; }
        }

        static private String carPort;

        static public String port
        {
            get { return carPort; }
            set { carPort = value; }
        }
        
    }
}
