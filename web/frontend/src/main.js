import Vue from 'vue'
import Vuetify from "vuetify";
import "vuetify/dist/vuetify.min.css";
import App from './App.vue'
import router from './router'
import vuetify from './plugins/vuetify'
import 'material-design-icons-iconfont/dist/material-design-icons.css'
import Sidebar from "./components/Sidebar.vue"
import Cards from "./components/Cards.vue"

Vue.use(Vuetify);
Vue.config.productionTip = false
Vue.component("app-sidebar", Sidebar);
Vue.component("app-cards", Cards);

new Vue({
  router,
  vuetify,
  render: h => h(App)
}).$mount('#app')

