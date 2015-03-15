using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=391641
/*
 *mam 2 odcienie na 2 monitorach ale tak taki mógłbyś zrobić na tym guziku tak jakby poziom paliwa(prondu na bateriach w pojezdie) zrobić to jako fioletowy płyn ktury by się poruszał jak płyn w szklanej kuli kiedy ruszasz telefonem i im mniej tego płynu tym mniej zostało energi w bateriach
 */
namespace Driver
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private Configuration appConf = new Configuration(new Uri("Configuration/configuration.xml", UriKind.RelativeOrAbsolute), new Uri("Configuration/configurationSchema.xsd", UriKind.RelativeOrAbsolute));
        private CommandSender senderMessager = new CommandSender();        
        public MainPage()
        {
            this.InitializeComponent();
            
            this.NavigationCacheMode = NavigationCacheMode.Required;
        }

        /// <summary>
        /// Invoked when this page is about to be displayed in a Frame.
        /// </summary>
        /// <param name="e">Event data that describes how this page was reached.
        /// This parameter is typically used to configure the page.</param>
        protected override void OnNavigatedTo(NavigationEventArgs e)
        {
            // TODO: Prepare page for display here.

            // TODO: If your application contains multiple pages, ensure that you are
            // handling the hardware Back button by registering for the
            // Windows.Phone.UI.Input.HardwareButtons.BackPressed event.
            // If you are using the NavigationHelper provided by some templates,
            // this event is handled for you.
        }

        private void _throttle_PointerPressed(object sender, PointerRoutedEventArgs e)
        {
            SolidColorBrush brakesBlack = new SolidColorBrush();
            brakesBlack.Color = Windows.UI.Color.FromArgb(255, 0, 0 ,0);
            throttle.Fill = brakesBlack;
        }

        private void _brakes_PointerPressed(object sender, PointerRoutedEventArgs e)
        {
            SolidColorBrush brakesBlack = new SolidColorBrush();
            brakesBlack.Color = Windows.UI.Color.FromArgb(255, 0, 0, 0);
            brakes.Fill = brakesBlack;
        }

        private void brakes_PointerReleased(object sender, PointerRoutedEventArgs e)
        {
            SolidColorBrush brakesBlack = new SolidColorBrush();
            brakesBlack.Color = Windows.UI.Color.FromArgb(255, 89, 1, 1);
            brakes.Fill = brakesBlack;
        }

        private void throttle_PointerReleased(object sender, PointerRoutedEventArgs e)
        {
            SolidColorBrush brakesBlack = new SolidColorBrush();
            brakesBlack.Color = Windows.UI.Color.FromArgb(255, 59, 9, 255);
            throttle.Fill = brakesBlack;
        }

        private void Right_PointerPressed(object sender, PointerRoutedEventArgs e)
        {
            _rightSteerAnimation.Begin();
        }

        private void Right_PointerReleased(object sender, PointerRoutedEventArgs e)
        {
            _rightSteerAnimationTouchUp.Begin();
        }

        private void Left_PointerPressed(object sender, PointerRoutedEventArgs e)
        {
            _leftSteer.Begin();
        }

        private void Left_PointerReleased(object sender, PointerRoutedEventArgs e)
        {
            _leftSteerTouchUp.Begin();
        }

        private void _settings_PointerPressed(object sender, PointerRoutedEventArgs e)
        {
            Frame.Navigate(typeof(Settings));
        }
        private void onClickSend(object sender, RoutedEventArgs e)
        {
            FrameworkElement element = sender as FrameworkElement;
            if (element.Name == "Brakes")
            {
                senderMessager.sendMessage("brake");
            }else if(element.Name == "Left")
            {
                senderMessager.sendMessage("left");
            }else if(element.Name == "brakes")
            {
                senderMessager.sendMessage("brake");
            }else if(element.Name == "throttle")
            {
                senderMessager.sendMessage("throttle");
            }else if(element.Name == "Right")
            {
                senderMessager.sendMessage("right");
            }
        }
        private void onUnclickSend(object sender, RoutedEventArgs e)
        {
            senderMessager.sendMessage("stop");
        }
        private void Grid_Loaded(object sender, RoutedEventArgs e)
        {
            Right.PointerPressed += onClickSend;
            Left.PointerPressed += onClickSend;
            brakes.PointerPressed += onClickSend;
            throttle.PointerPressed += onClickSend;
            Right.PointerReleased += onUnclickSend;
            Left.PointerReleased += onUnclickSend;
            brakes.PointerReleased += onUnclickSend;
            throttle.PointerReleased += onUnclickSend;

        }
    }
}
