import http from '../http-common'

class RestaurantDataService {
  getAll(page = 0) {
    return http.get(`?page=${page}`);
  }

  createRevie

}
export default new RestaurantDataService();