<?php

/**
 * @file
 * Class ExchangeRatesEntityMetadataController.
 */

/**
 * Extends EntityDefaultMetadataController.
 */
class ExchangeRatesEntityMetadataController extends EntityDefaultMetadataController {

  /**
   * It describes the entity.
   *
   * Processing timestamp.
   *
   * @return array
   *   Property info.
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $info[$this->type]['properties']['timestamp'] = array(
      'label' => t("timestamp"),
      'type' => 'date',
      'description' => t("timestamp"),
      'schema field' => 'timestamp',
      'setter callback' => 'entity_property_verbatim_set',
    );
    return $info;
  }

}
