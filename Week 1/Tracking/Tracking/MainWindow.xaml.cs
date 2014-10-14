using System;
using System.Collections.Generic;
using System.Linq;
using System.Data;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Tracking {
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window {
        public DataTable packageTable_datatable;

        public MainWindow() {
            InitializeComponent();
            packageTable_datatable = new DataTable();
        }

        private void textbox_packagecode_GotFocus(object sender, RoutedEventArgs e) {
            textbox_packagecode.Text = ""; 
        }

        private void textbox_packagecode_LostFocus(object sender, RoutedEventArgs e) {
            if (textbox_packagecode.Text == "") {
                textbox_packagecode.Text = "Kod przesyłki"; 
            }
        }

        private void button_search_Click(object sender, RoutedEventArgs e)
        {

            //textbox_packagecode.
        }

        
    }
}
