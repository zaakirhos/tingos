import http from '../http-common'

class RestaurantDataService {
  getAll(page = 0) {
    return http.get(`restaurants?page=${page}`);
  }

}
export default new RestaurantDataService();