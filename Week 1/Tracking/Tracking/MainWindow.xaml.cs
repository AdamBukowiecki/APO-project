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
        public AvailablePackageList apl_database;

        public MainWindow() {
            InitializeComponent();
            packageTable_datatable = new DataTable();
            packageTable_datatable.Columns.Add("ID");
            packageTable_datatable.Columns.Add("Adres");
            packageTable_datatable.Columns.Add("Stan");
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
            int intcode = 0;
            try {
                if (textbox_packagecode.Text != "" && textbox_packagecode.Text != "Kod przesyłki")
                {
                    intcode = Convert.ToInt32(textbox_packagecode.Text);
                }
            }
            catch (FormatException) {
                intcode = 0;
            }

            Package retrievedPackage = apl_database.getPackageById(intcode);
            if (!(retrievedPackage.Equals(null)))
            {
                foreach (Location loc in retrievedPackage.locList.getLocationList()) {
                    packageTable_datatable.Rows.Add(loc.id, loc.address, loc.state);
                }
            }  
        }        
    }
}
