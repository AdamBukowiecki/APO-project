using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tracking
{
    /// <summary>
    /// Contains all registered packages. 
    /// </summary>
    public sealed class AvailablePackageList {
        private List<Package> packList;

        public AvailablePackageList() {
            this.packList = new List<Package>();
            this.generateBase();
        }

        /// <summary>
        /// Generates random data for example
        /// </summary>
        private void generateBase() {
            LocationList l1 = new LocationList();
            Package p1 = new Package(123456, l1);
            this.packList.Add(p1);
        }

        public Package getPackageById(int p_id){
            LocationList loctemp = new LocationList();
            Package result = new Package(0, loctemp);
            foreach (Package pack in packList)
            {
                if (pack.getPackageId() == p_id)
                {
                    result = pack;
                }
            }
            return result;
        }

    }
}
