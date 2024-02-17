import http from '../http-common'

class RestaurantDataService {
  getAll(page = 0) {
    return http.get(`?page=${page}`);
  }

  create

}
export default new RestaurantDataService();