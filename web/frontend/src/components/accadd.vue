<template>
            <v-dialog v-model="dialog" persistent max-width="600px">
            <template v-slot:activator="{ on, attrs }">
                <v-btn color="success" dark rounded small v-bind="attrs" v-on="on">
                <v-icon left> mdi-account-plus
                </v-icon>
                Add
                </v-btn>
            </template>
            <v-card color="blue-grey darken-3">
            <v-toolbar rounded="" class="cyan darken-1">
                
                <v-card-title class="font-weight-bold text-h5 blue-grey--text text--darken-3">
                <span class="text-h5">User Profile</span>
                </v-card-title>
            </v-toolbar>
                <v-card-text>
                    <v-container>
                        <v-row>
                            <v-col>
                                <v-text-field
                                dark
                                label="Account name"
                                name="Account name"
                                id="Account name"
                                prepend-icon="person"
                                color="cyan darken-1"
                                required
                                ></v-text-field>
                            </v-col>
                        </v-row>
                    </v-container>
                </v-card-text>
                <v-card-actions>
                    <v-spacer></v-spacer>
                        <v-btn
                            color="cyan darken-1"
                            text
                            @click="dialog = false"
                        >
                            Close
                        </v-btn>
                        <v-btn
                            color="cyan darken-1"
                            text
                            @click="dialog = false"
                        >
                            Save
                        </v-btn>
                </v-card-actions>
            </v-card>
            </v-dialog>
</template>

<script>
  export default {
    data: () => ({
      dialog: false,
    }),   
  }
</script>