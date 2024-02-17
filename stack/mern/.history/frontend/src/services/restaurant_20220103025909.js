import http from '../http-common'

class RestaurantDataService {
  getAll() {
    return http.get(`?`);
  }

}
export default new RestaurantDataService();