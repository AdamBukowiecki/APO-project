using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tracking {
    /// <summary>
    /// Contains list of locations for particular package.
    /// </summary>
    public sealed class LocationList {
        private List<Location> loc_list;

        public LocationList() {
        
        }

        public List<Location> getLocationList() {
            return loc_list;
        }

    }
}
