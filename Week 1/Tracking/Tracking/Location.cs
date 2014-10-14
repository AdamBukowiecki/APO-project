using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Tracking {
    /// <summary>
    /// Contains data about location of package.
    /// </summary>
    public sealed class Location {
        public int id;
        public String address;
        public String state;

        public Location(int id_loc, String address_loc, String stateDescription) {
            this.id = id_loc;
            this.address = address_loc;
            this.state = stateDescription;
        }

        
    }
}
