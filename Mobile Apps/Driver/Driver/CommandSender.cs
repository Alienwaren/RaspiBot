using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Windows.Networking;
using Windows.Networking.Sockets;
using Windows.Storage.Streams;

namespace Driver
{
    class CommandSender
    {
        public CommandSender()
        {
            List<HostName> hostnames = Windows.Networking.Connectivity.NetworkInformation.GetHostNames().ToList();
            localIp = hostnames[2];
            if (!String.IsNullOrEmpty(Options.ip) && !String.IsNullOrEmpty(Options.port))
            {
                ip = Options.ip;
                port = Options.port;
            }
            try
            {
                socket.BindEndpointAsync(localIp, port);
            }
            catch (Exception e)
            {

                throw;
            }
        }
        async public void sendMessage(string message)
        {
            
            if (message.Length <= 10 && !String.IsNullOrEmpty(message))
            {
                var stream = await socket.GetOutputStreamAsync(new EndpointPair(localIp, port, new HostName(ip), port));
                DataWriter writer = new DataWriter();
                writer.WriteString(message);
                IBuffer buffer = writer.DetachBuffer();
                await stream.WriteAsync(buffer);
            }
            else
            {
            }
        }
        private DatagramSocket socket = new DatagramSocket();
        private String ip = "";
        private String port = "";
        private HostName localIp;

    }
}
