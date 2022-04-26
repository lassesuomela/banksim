<template>
  <v-navigation-drawer class="cyan darken-1" 
        permanent
        app>
    <v-col
      height="140"
      class="blue-grey darken-3"
    >
      <div class="text-center">
        <v-avatar class="mb-4" color="grey darken-1" size="64">
          <v-img v-if="this.loaded"
            :aspect-ratio="30"
            :src= "this.profilePicture"
          />
        </v-avatar>
        <h2 class="cyan--text text--darken-1">{{fname}}</h2>
      </div>
    </v-col>
    <v-divider></v-divider>
    <v-list rounded dense>
        <v-list-item class="item" v-for="link in links" :key="link.text" router :to="link.route">
          <v-list-item-action>
            <v-icon class="#202227--text">{{ link.icon }}</v-icon>
          </v-list-item-action>
          <v-list-item-content>
            <v-list-item-title class="#202227--text">{{ link.text }}</v-list-item-title>
          </v-list-item-content>
        </v-list-item>
    </v-list>
  </v-navigation-drawer>
</template>

<script>
import axios from "../axios"
export default {
  name: "Sidebar",
  props: ["drawer"],
  data() {
    return {
      links: [
        { icon: 'mdi-account', text: 'Home', route: '/home' },
        { icon: 'mdi-cash', text: 'Accounts', route: '/accounts' },
        { icon: 'mdi-credit-card', text: 'Cards', route: '/cards' },
        { icon: 'mdi-door', text: 'Logout', route: '/logout' }
      ],
      fname: "",
      profilePicture: "http://localhost:3000/uploads/",
      loaded: false
    };
  },
  methods:{
    async getUserInfo(){
      let response = await axios.get("/api/user/info");
      this.fname = response.data.fname;
      this.profilePicture += response.data.picture;

      this.loaded = true;
    }
  },
  mounted(){
    this.getUserInfo();
  }
};
</script>


<style scoped>
  .item {
    margin: 5px;
    border-radius: 4px;
  }
  .item:hover {
    background: #0097A7;
  }
  .item:active {
    background: #00838F;
  }
</style>



