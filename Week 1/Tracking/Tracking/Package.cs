using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tracking {
    /// <summary>
    /// Contains data of particular package.
    /// </summary>
    public sealed class Package {
        public int id;
        public LocationList locList;

        public Package(int pid, LocationList locationList) {
            this.id = pid;
            this.locList = locationList;
        }

        public int getPackageId() {
            return this.id;
        }

        public LocationList getLocationList(){
            return this.locList;
        }
    }
}