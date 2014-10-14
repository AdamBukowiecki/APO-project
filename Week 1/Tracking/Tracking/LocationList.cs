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

        /// <summary>
        /// generates random data for example
        /// </summary>
        public LocationList() {
            loc_list = new List<Location>();
            Location local1 = new Location(1, "Poznań, ul. Wierzbięcice 16A", "Nadanie przesyłki");
            Location local2 = new Location(2, "Swarzędz", "Magazyn");
            Location local3 = new Location(3, "Poznań ul. Kórnicka 24", "Dostarczenie do paczkomatu");
            loc_list.Add(local1);
            loc_list.Add(local2);
            loc_list.Add(local3);
        }

        public List<Location> getLocationList() {
            return loc_list;
        }

    }
}
