import http from '../http-common'

class RestaurantDataService {
  getAll() {
    return http.get(`?page=${page}`);
  }

}
export default new RestaurantDataService();